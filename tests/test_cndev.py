from mlu_api import cndev


def test_get_device_count():
    cndev.get_device_count()


def test_get_core_utilizations():
    cndev.get_core_utilizations(0)
