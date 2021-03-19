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
    /// Please note the command SetBeiDouEphemerisBoolParams is deprecated since 21.3. You may use SetBeiDouEphBoolParamForEachSV.
    /// 
    /// Set BeiDou ephemeris boolean parameter value for all satellites
    ///
    /// Name      Type       Description
    /// --------- ---------- --------------------------------------------------------------------------------------------------
    /// ParamName string     Refer to SetBeiDouEphBoolParamForSV for accepted names
    /// Val       array bool Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class SetBeiDouEphemerisBoolParams;
    typedef std::shared_ptr<SetBeiDouEphemerisBoolParams> SetBeiDouEphemerisBoolParamsPtr;
    
    
    class SetBeiDouEphemerisBoolParams : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetBeiDouEphemerisBoolParams();

      SetBeiDouEphemerisBoolParams(const std::string& paramName, const std::vector<bool>& val);
  
      static SetBeiDouEphemerisBoolParamsPtr create(const std::string& paramName, const std::vector<bool>& val);
      static SetBeiDouEphemerisBoolParamsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** paramName ****
      std::string paramName() const;
      void setParamName(const std::string& paramName);


      // **** val ****
      std::vector<bool> val() const;
      void setVal(const std::vector<bool>& val);
    };
  }
}

