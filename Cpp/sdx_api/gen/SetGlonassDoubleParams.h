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
    /// Please note the command SetGlonassDoubleParams is deprecated since 21.3. You may use SetGlonassEphDoubleParamForEachSV.
    /// 
    /// Set GLONASS parameter value for all satellites
    ///
    /// Name      Type         Description
    /// --------- ------------ --------------------------------------------------------------------------------------------------
    /// ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names
    /// Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetGlonassDoubleParams;
    typedef std::shared_ptr<SetGlonassDoubleParams> SetGlonassDoubleParamsPtr;
    
    
    class SetGlonassDoubleParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetGlonassDoubleParams();

      SetGlonassDoubleParams(const std::string& paramName, const std::vector<double>& val);

      static SetGlonassDoubleParamsPtr create(const std::string& paramName, const std::vector<double>& val);
      static SetGlonassDoubleParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

