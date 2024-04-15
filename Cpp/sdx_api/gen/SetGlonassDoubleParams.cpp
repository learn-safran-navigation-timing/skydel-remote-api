
#include "SetGlonassDoubleParams.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassDoubleParams::CmdName = "SetGlonassDoubleParams";
    const char* const SetGlonassDoubleParams::Documentation = "Please note the command SetGlonassDoubleParams is deprecated since 21.3. You may use SetGlonassEphDoubleParamForEachSV.\n"
      "\n"
      "Set GLONASS parameter value for all satellites\n"
      "\n"
      "Name      Type         Description\n"
      "--------- ------------ --------------------------------------------------------------------------------------------------\n"
      "ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names\n"
      "Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const SetGlonassDoubleParams::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGlonassDoubleParams);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGlonassDoubleParams);


    SetGlonassDoubleParams::SetGlonassDoubleParams()
      : CommandBase(CmdName, TargetId)
    {}

    SetGlonassDoubleParams::SetGlonassDoubleParams(const std::string& paramName, const std::vector<double>& val)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
    }

    SetGlonassDoubleParamsPtr SetGlonassDoubleParams::create(const std::string& paramName, const std::vector<double>& val)
    {
      return std::make_shared<SetGlonassDoubleParams>(paramName, val);
    }

    SetGlonassDoubleParamsPtr SetGlonassDoubleParams::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassDoubleParams>(ptr);
    }

    bool SetGlonassDoubleParams::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGlonassDoubleParams::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGlonassDoubleParams::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val"}; 
      return names; 
    }


    int SetGlonassDoubleParams::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGlonassDoubleParams::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGlonassDoubleParams::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGlonassDoubleParams::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGlonassDoubleParams::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
