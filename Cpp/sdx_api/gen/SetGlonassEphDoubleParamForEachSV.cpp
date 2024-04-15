
#include "SetGlonassEphDoubleParamForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGlonassEphDoubleParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGlonassEphDoubleParamForEachSV::CmdName = "SetGlonassEphDoubleParamForEachSV";
    const char* const SetGlonassEphDoubleParamForEachSV::Documentation = "Set GLONASS parameter value for all satellites\n"
      "\n"
      "Name      Type         Description\n"
      "--------- ------------ --------------------------------------------------------------------------------------------------\n"
      "ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names\n"
      "Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const SetGlonassEphDoubleParamForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGlonassEphDoubleParamForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGlonassEphDoubleParamForEachSV);


    SetGlonassEphDoubleParamForEachSV::SetGlonassEphDoubleParamForEachSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetGlonassEphDoubleParamForEachSV::SetGlonassEphDoubleParamForEachSV(const std::string& paramName, const std::vector<double>& val)
      : CommandBase(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
    }

    SetGlonassEphDoubleParamForEachSVPtr SetGlonassEphDoubleParamForEachSV::create(const std::string& paramName, const std::vector<double>& val)
    {
      return std::make_shared<SetGlonassEphDoubleParamForEachSV>(paramName, val);
    }

    SetGlonassEphDoubleParamForEachSVPtr SetGlonassEphDoubleParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGlonassEphDoubleParamForEachSV>(ptr);
    }

    bool SetGlonassEphDoubleParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
        ;

    }

    std::string SetGlonassEphDoubleParamForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGlonassEphDoubleParamForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val"}; 
      return names; 
    }


    int SetGlonassEphDoubleParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetGlonassEphDoubleParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetGlonassEphDoubleParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> SetGlonassEphDoubleParamForEachSV::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void SetGlonassEphDoubleParamForEachSV::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
