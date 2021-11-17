#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssEphDoubleParamForSV.
    ///
    /// Name      Type   Description
    /// --------- ------ ----------------------------------------------------------------------------------
    /// SvId      int    The satellite's SV ID 1..10 (use 0 to apply to all satellites)
    /// ParamName string In meters:  "Crs", "Crc"
    ///                  In radians: "Cis", "Cic", "Cus", "Cuc"
    ///                  In seconds: "Tgd", "IscL1Ca", "IscL2C", "IscL5I5", "IscL5Q5", "IscL1CP", "IscL1CD"
    /// Val       double Parameter value (see ParamName above for unit)
    ///

    class GetQzssEphDoubleParamForSVResult;
    typedef std::shared_ptr<GetQzssEphDoubleParamForSVResult> GetQzssEphDoubleParamForSVResultPtr;
    typedef GetQzssEphDoubleParamForSVResult GetQzssEphemerisDoubleParamResult;
    typedef std::shared_ptr<GetQzssEphemerisDoubleParamResult> GetQzssEphemerisDoubleParamResultPtr;
    
    class GetQzssEphDoubleParamForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphDoubleParamForSVResult();

      GetQzssEphDoubleParamForSVResult(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);
  
      static GetQzssEphDoubleParamForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::string& paramName, double val);
      static GetQzssEphDoubleParamForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      double val() const;
      void setVal(double val);
    };
  }
}

