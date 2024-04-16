#ifndef __SUPERA_FLASH_CXX__
#define __SUPERA_FLASH_CXX__

#include "Flash.h"
#include "supera/base/meatloaf.h"
#include <numeric> // std::accumulate()

namespace supera {

    Flash::Flash(double time, double timeWidth, double absTime, unsigned int frame,
        std::vector<double> PEPerOpDet,
        bool inBeamFrame, int onBeamTime, double fastToTotal,
        double xCenter, double xWidth,
        double yCenter, double yWidth,
        double zCenter, double zWidth,
        std::vector<double> wireCenters,
        std::vector<double> wireWidths,
        InstanceID_t id,
        unsigned int tpc)
        : _id(id)
        , _time(time)
        , _tpc(tpc)
        , _timeWidth(timeWidth)
        , _absTime  (absTime)
        , _frame    (frame)
        , _PEPerOpDet (PEPerOpDet)
        , _wireCenters (wireCenters)
        , _wireWidths  (wireWidths)
        , _xCenter     (xCenter)
        , _xWidth      (xWidth)
        , _yCenter     (yCenter)
        , _yWidth      (yWidth)
        , _zCenter     (zCenter)
        , _zWidth      (zWidth)
        , _fastToTotal (fastToTotal)
        , _inBeamFrame (inBeamFrame)
        , _onBeamTime  (onBeamTime)

    {}

    double Flash::TotalPE() const {
        return std::accumulate(_PEPerOpDet.begin(), _PEPerOpDet.end(), 0.0);
    }

}
#endif
