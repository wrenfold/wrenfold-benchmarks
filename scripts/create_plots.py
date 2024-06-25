"""
Create plots of benchmarks for the website.
"""

from pathlib import Path
import argparse
import collections
import json
import pandas as pd
import plotly.graph_objects as go
import subprocess
import tempfile
import typing as T


def plot_samples(
    benchmark_name: str,
    samples: T.List[T.Tuple[str, float]],
    output_dir: Path,
    all_variants: T.List[str],
    full_outputs: bool,
):
    """Plot all times for a given benchmark."""

    times_dict = collections.OrderedDict(sorted(samples))
    wrenfold_time = times_dict["Wrenfold"]

    names = list(times_dict.keys())
    times = [t / wrenfold_time for t in times_dict.values()]
    colors = [all_variants.index(n) for n in names]

    fig = go.Figure()
    fig.add_trace(
        go.Bar(x=names, y=times, marker=dict(color=colors, colorscale="viridis"), legend='legend'))

    fig.add_hline(y=1, line_dash="dot")

    fig.update_layout(
        title=f"Benchmark: {benchmark_name}", xaxis_title="Variant", yaxis_title="Relative time")

    html_args = dict()
    if not full_outputs:
        html_args.update(full_html=False, default_width="80%", include_plotlyjs="cdn")

    fig.update_layout(template="plotly")
    with open(output_dir / f"{benchmark_name}.html", "wb") as handle:
        handle.write(fig.to_html(**html_args).encode("utf8"))

    # TODO: Support dark mode?
    # fig.update_layout(template="plotly_dark")
    # with open(output_dir / f"{benchmark_name}_dark.html", "wb") as handle:
    #   handle.write(fig.to_html(**html_args).encode("utf8"))


def run_benchmarks() -> T.Dict:
    """Invoke the benchmark suite and load the results."""
    with tempfile.TemporaryDirectory(prefix="benchmarks_") as tmp_dir:
        tmp_file = Path(tmp_dir) / "data.json"
        command = [
            Path(__file__).parent.parent.absolute() / "build" / "run_benchmarks",
            "--benchmark_min_warmup_time=1.0",
            "--benchmark_format=json",
            f"--benchmark_out={str(tmp_file)}",
        ]
        subprocess.check_call(command)

        # Read back the result:
        with open(tmp_file, "r") as handle:
            return json.load(handle)


def main(args: argparse.Namespace):
    if args.json is None:
        data = run_benchmarks()
    else:
        with open(args.json, "r") as handle:
            data = json.load(handle)

    # Collate benchmakrs into a dict mapping from: name -> variants
    benchmarks: T.Dict[str, T.List[T.Tuple[str, float]]] = collections.defaultdict(list)
    all_variants = set()
    for run in data["benchmarks"]:
        name, _ = run["name"].split("/")
        _, bench_name, bench_variant = name.split("_")

        all_variants.add(bench_variant)
        benchmarks[bench_name].append((bench_variant, run["real_time"]))

    all_variants = sorted(all_variants)

    for name, samples in benchmarks.items():
        plot_samples(
            benchmark_name=name if not args.suffix else f"{name}-{args.suffix}",
            samples=samples,
            output_dir=Path(args.output),
            all_variants=all_variants,
            full_outputs=args.full)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--json", type=str, help="Path to benchmark JSON file", default=None)
    parser.add_argument("--output", type=str, help="Output directory", required=True)
    parser.add_argument("--full", action="store_true", help="Make complete HTML pages")
    parser.add_argument("--suffix", type=str, help="Suffix for chart names.")
    return parser.parse_args()


if __name__ == "__main__":
    main(parse_args())
