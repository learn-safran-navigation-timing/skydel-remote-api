
#include "gen/SetGlonassDoubleParams.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassDoubleParams
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassDoubleParams::CmdName = "SetGlonassDoubleParams";
    const char* const SetGlonassDoubleParams::Documentation = "Please note the command SetGlonassDoubleParams is deprecated since 21.3. You may use SetGlonassEphDoubleParamForEachSV.\n\nSet GLONASS parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetGlonassDoubleParams);


    SetGlonassDoubleParams::SetGlonassDoubleParams()
      : CommandBase(CmdName)
    {}

    SetGlonassDoubleParams::SetGlonassDoubleParams(const std::string& paramName, const std::vector<double>& val)
      : CommandBase(CmdName)
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
