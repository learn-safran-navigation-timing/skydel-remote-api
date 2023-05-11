#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GLONASS parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetGlonassEphDoubleParamForEachSV;
    typedef std::shared_ptr<SetGlonassEphDoubleParamForEachSV> SetGlonassEphDoubleParamForEachSVPtr;
    
    
    class SetGlonassEphDoubleParamForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGlonassEphDoubleParamForEachSV();

      SetGlonassEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val);

      static SetGlonassEphDoubleParamForEachSVPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetGlonassEphDoubleParamForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<double> val() const;
      void setVal(const std::vector<double>& val);
    };
    
  }
}

