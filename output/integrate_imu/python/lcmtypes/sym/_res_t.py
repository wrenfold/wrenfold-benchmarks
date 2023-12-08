# This file automatically generated by skymarshal
# DO NOT MODIFY BY HAND
# fmt: off
# isort: off
# mypy: disallow-untyped-defs

import copy
import typing as T  # pylint: disable=unused-import

from io import BytesIO
import struct
from lcmtypes.eigen_lcm._Vector3d import Vector3d
from lcmtypes.eigen_lcm._Vector4d import Vector4d
from lcmtypes.eigen_lcm._VectorXd import VectorXd

class res_t(object):
    __slots__ = ["i_R_k", "i_p_k", "i_v_k", "k_D_j", "k_D_measurements", "k_D_bias"]  # type: T.List[str]

    def __init__(
        self,
        i_R_k=None,  # type: Vector4d
        i_p_k=None,  # type: Vector3d
        i_v_k=None,  # type: Vector3d
        k_D_j=None,  # type: VectorXd
        k_D_measurements=None,  # type: VectorXd
        k_D_bias=None,  # type: VectorXd
        _skip_initialize=False,  # type: bool
    ):
        # type: (...) -> None
        """ If _skip_initialize is True, all other constructor arguments are ignored """
        if _skip_initialize:
            return
        self.i_R_k = Vector4d._default() if i_R_k is None else i_R_k  # type: Vector4d
        self.i_p_k = Vector3d._default() if i_p_k is None else i_p_k  # type: Vector3d
        self.i_v_k = Vector3d._default() if i_v_k is None else i_v_k  # type: Vector3d
        self.k_D_j = VectorXd._default() if k_D_j is None else k_D_j  # type: VectorXd
        self.k_D_measurements = VectorXd._default() if k_D_measurements is None else k_D_measurements  # type: VectorXd
        self.k_D_bias = VectorXd._default() if k_D_bias is None else k_D_bias  # type: VectorXd

    @staticmethod
    def from_all_fields(
        i_R_k,  # type: Vector4d
        i_p_k,  # type: Vector3d
        i_v_k,  # type: Vector3d
        k_D_j,  # type: VectorXd
        k_D_measurements,  # type: VectorXd
        k_D_bias,  # type: VectorXd
    ):
        # type: (...) -> res_t
        return res_t(
            i_R_k=i_R_k,
            i_p_k=i_p_k,
            i_v_k=i_v_k,
            k_D_j=k_D_j,
            k_D_measurements=k_D_measurements,
            k_D_bias=k_D_bias,
        )

    @staticmethod
    def _skytype_meta():
        # type: () -> T.Dict[str, str]
        return dict(
            type="struct",
            package="sym",
            name="res_t",
        )

    @classmethod
    def _default(cls):
        # type: () -> res_t
        return cls()

    def __repr__(self):
        # type: () -> str
        return "res_t({})".format(
            ", ".join("{}={}".format(name, repr(getattr(self, name))) for name in self.__slots__))

    def __eq__(self, other):
        # type: (object) -> bool
        if not isinstance(other, res_t):
            return NotImplemented
        return (
            (self.i_R_k==other.i_R_k) and
            (self.i_p_k==other.i_p_k) and
            (self.i_v_k==other.i_v_k) and
            (self.k_D_j==other.k_D_j) and
            (self.k_D_measurements==other.k_D_measurements) and
            (self.k_D_bias==other.k_D_bias)
        )
    # Disallow hashing for python struct lcmtypes.
    __hash__ = None  # type: ignore

    def encode(self):
        # type: () -> bytes
        buf = BytesIO()
        buf.write(res_t._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        # type: (T.BinaryIO) -> None
        if hasattr(self.i_R_k, '_get_packed_fingerprint'):
            assert self.i_R_k._get_packed_fingerprint() == Vector4d._get_packed_fingerprint()
        else:
            assert self.i_R_k._get_hash_recursive([]) == Vector4d._get_hash_recursive([])
        self.i_R_k._encode_one(buf)
        if hasattr(self.i_p_k, '_get_packed_fingerprint'):
            assert self.i_p_k._get_packed_fingerprint() == Vector3d._get_packed_fingerprint()
        else:
            assert self.i_p_k._get_hash_recursive([]) == Vector3d._get_hash_recursive([])
        self.i_p_k._encode_one(buf)
        if hasattr(self.i_v_k, '_get_packed_fingerprint'):
            assert self.i_v_k._get_packed_fingerprint() == Vector3d._get_packed_fingerprint()
        else:
            assert self.i_v_k._get_hash_recursive([]) == Vector3d._get_hash_recursive([])
        self.i_v_k._encode_one(buf)
        if hasattr(self.k_D_j, '_get_packed_fingerprint'):
            assert self.k_D_j._get_packed_fingerprint() == VectorXd._get_packed_fingerprint()
        else:
            assert self.k_D_j._get_hash_recursive([]) == VectorXd._get_hash_recursive([])
        self.k_D_j._encode_one(buf)
        if hasattr(self.k_D_measurements, '_get_packed_fingerprint'):
            assert self.k_D_measurements._get_packed_fingerprint() == VectorXd._get_packed_fingerprint()
        else:
            assert self.k_D_measurements._get_hash_recursive([]) == VectorXd._get_hash_recursive([])
        self.k_D_measurements._encode_one(buf)
        if hasattr(self.k_D_bias, '_get_packed_fingerprint'):
            assert self.k_D_bias._get_packed_fingerprint() == VectorXd._get_packed_fingerprint()
        else:
            assert self.k_D_bias._get_hash_recursive([]) == VectorXd._get_hash_recursive([])
        self.k_D_bias._encode_one(buf)

    @staticmethod
    def decode(data):
        # type: (T.Union[bytes, T.BinaryIO]) -> res_t
        # NOTE(eric): This function can technically accept either a BinaryIO or
        # anything that supports the C++ Buffer Protocol,
        # which is unspecifiable in type hints.

        if hasattr(data, "read"):
            # NOTE(eric): mypy isn't able to figure out the hasattr check
            buf = T.cast(T.BinaryIO, data)
        else:
            buf = BytesIO(T.cast(bytes, data))

        if buf.read(8) != res_t._get_packed_fingerprint():
            raise ValueError("Decode error")
        return res_t._decode_one(buf)

    @staticmethod
    def _decode_one(buf):
        # type: (T.BinaryIO) -> res_t
        self = res_t(_skip_initialize=True)
        self.i_R_k = Vector4d._decode_one(buf)
        self.i_p_k = Vector3d._decode_one(buf)
        self.i_v_k = Vector3d._decode_one(buf)
        self.k_D_j = VectorXd._decode_one(buf)
        self.k_D_measurements = VectorXd._decode_one(buf)
        self.k_D_bias = VectorXd._decode_one(buf)
        return self

    @staticmethod
    def _get_hash_recursive(parents):
        # type: (T.List[T.Type]) -> int
        if res_t in parents: return 0
        newparents = parents + [res_t]
        tmphash = (0x9217d8818a28bd78+ Vector4d._get_hash_recursive(newparents)+ Vector3d._get_hash_recursive(newparents)+ Vector3d._get_hash_recursive(newparents)+ VectorXd._get_hash_recursive(newparents)+ VectorXd._get_hash_recursive(newparents)+ VectorXd._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash = (((tmphash<<1)&0xffffffffffffffff)  + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash

    _packed_fingerprint = None  # type: T.Optional[bytes]

    @staticmethod
    def _get_packed_fingerprint():
        # type: () -> bytes
        if res_t._packed_fingerprint is None:
            res_t._packed_fingerprint = struct.pack(">Q", res_t._get_hash_recursive([]))
        return res_t._packed_fingerprint

    def deepcopy(self, **kwargs):
        # type: (**T.Any) -> res_t
        """
        Deep copy of this LCM type

        Returns a copy w/ members specified by kwargs replaced with new values specified by kwargs.
        """
        result = copy.deepcopy(self)
        for key in kwargs:
            if not hasattr(result, key):
                raise KeyError("Type res_t does not have attribute: " + str(key))
            setattr(result, key, kwargs[key])
        return result