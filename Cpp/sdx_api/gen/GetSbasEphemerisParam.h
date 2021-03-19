#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSbasEphemerisParam is deprecated since 21.3. You may use GetSbasEphParamsForSV.
    /// 
    /// Get parameters for a SBAS satellite ephemeris
    ///
    /// Name      Type   Description
    /// --------- ------ -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Prn       int    The satellite's PRN
    /// Parameter string Parameter's names. Can be : "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z", "VelocityX", "VelocityY", "VelocityZ", "AccelerationX", "AccelerationY", "AccelerationZ", "Health", "URA".
    ///

    class GetSbasEphemerisParam;
    typedef std::shared_ptr<GetSbasEphemerisParam> GetSbasEphemerisParamPtr;
    
    
    class GetSbasEphemerisParam : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasEphemerisParam();

      GetSbasEphemerisParam(int prn, const std::string& parameter);
  
      static GetSbasEphemerisParamPtr create(int prn, const std::string& parameter);
      static GetSbasEphemerisParamPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** parameter ****
      std::string parameter() const;
      void setParameter(const std::string& parameter);
    };
  }
}

