#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasEphemerisParam.
    ///
    /// Name       Type   Description
    /// ---------- ------ ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Prn        int    The satellite's PRN number
    /// Parameter  string A list of pair of strings. The first will be the key and be from this list: "ClockBias", "RelativeFrequencyBias", "X", "Y", "Z", "VelocityX", "VelocityY", "VelocityZ", "AccelerationX", "AccelerationY", "AccelerationZ", "Health", URA. The Second argument will be the corresponding value.
    /// ValueParam string Parameter's value.
    ///

    class GetSbasEphemerisParamResult;
    typedef std::shared_ptr<GetSbasEphemerisParamResult> GetSbasEphemerisParamResultPtr;
    
    
    class GetSbasEphemerisParamResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasEphemerisParamResult();

      GetSbasEphemerisParamResult(CommandBasePtr relatedCommand, int prn, const std::string& parameter, const std::string& valueParam);
  
      static GetSbasEphemerisParamResultPtr create(CommandBasePtr relatedCommand, int prn, const std::string& parameter, const std::string& valueParam);
      static GetSbasEphemerisParamResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** parameter ****
      std::string parameter() const;
      void setParameter(const std::string& parameter);


      // **** valueParam ****
      std::string valueParam() const;
      void setValueParam(const std::string& valueParam);
    };
  }
}

