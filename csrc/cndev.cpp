#include <cndev.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <string>
unsigned int get_device_count() {
    cndevCardInfo_t cardNum;
    cardNum.version = CNDEV_VERSION_6;
    cndevCheckErrors(cndevGetDeviceCount(&cardNum));

    return cardNum.number;
}

std::vector<int> get_core_utilizations(int card_id) {
    cndevDevice_t devHandle;
    cndevCheckErrors(cndevGetDeviceHandleByIndex(card_id, &devHandle));

    cndevUtilizationInfo_t utilInfo;
    utilInfo.version = CNDEV_VERSION_6;
    cndevCheckErrors(cndevGetDeviceUtilizationInfo(&utilInfo, devHandle));

    const int default_core_nums = 80;
    std::vector<int> results(utilInfo.coreUtilization,
                             utilInfo.coreUtilization + default_core_nums);
    return results;
}

PYBIND11_MODULE(cndev, m) {
    m.doc() = "cndev module";

    cndevCheckErrors(cndevInit(0));

    m.def("get_device_count", &get_device_count);
    m.def("get_core_utilizations", &get_core_utilizations);
}
