
#include "GetGlonassEphDoubleParamForEachSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGlonassEphDoubleParamForEachSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGlonassEphDoubleParamForEachSVResult::CmdName = "GetGlonassEphDoubleParamForEachSVResult";
    const char* const GetGlonassEphDoubleParamForEachSVResult::Documentation = "Result of GetGlonassEphDoubleParamForEachSV.\n"
      "\n"
      "Name      Type         Description\n"
      "--------- ------------ --------------------------------------------------------------------------------------------------\n"
      "ParamName string       Refer to SetGlonassEphDoubleParamForSV for accepted names\n"
      "Val       array double Parameter value for each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)";
    const char* const GetGlonassEphDoubleParamForEachSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGlonassEphDoubleParamForEachSVResult);


    GetGlonassEphDoubleParamForEachSVResult::GetGlonassEphDoubleParamForEachSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGlonassEphDoubleParamForEachSVResult::GetGlonassEphDoubleParamForEachSVResult(const std::string& paramName, const std::vector<double>& val)
      : CommandResult(CmdName, TargetId)
    {

      setParamName(paramName);
      setVal(val);
    }

    GetGlonassEphDoubleParamForEachSVResult::GetGlonassEphDoubleParamForEachSVResult(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setParamName(paramName);
      setVal(val);
    }


    GetGlonassEphDoubleParamForEachSVResultPtr GetGlonassEphDoubleParamForEachSVResult::create(const std::string& paramName, const std::vector<double>& val)
    {
      return std::make_shared<GetGlonassEphDoubleParamForEachSVResult>(paramName, val);
    }

    GetGlonassEphDoubleParamForEachSVResultPtr GetGlonassEphDoubleParamForEachSVResult::create(CommandBasePtr relatedCommand, const std::string& paramName, const std::vector<double>& val)
    {
      return std::make_shared<GetGlonassEphDoubleParamForEachSVResult>(relatedCommand, paramName, val);
    }

    GetGlonassEphDoubleParamForEachSVResultPtr GetGlonassEphDoubleParamForEachSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGlonassEphDoubleParamForEachSVResult>(ptr);
    }

    bool GetGlonassEphDoubleParamForEachSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<double>>::is_valid(m_values["Val"])
        ;

    }

    std::string GetGlonassEphDoubleParamForEachSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGlonassEphDoubleParamForEachSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"ParamName", "Val"}; 
      return names; 
    }


    std::string GetGlonassEphDoubleParamForEachSVResult::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetGlonassEphDoubleParamForEachSVResult::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<double> GetGlonassEphDoubleParamForEachSVResult::val() const
    {
      return parse_json<std::vector<double>>::parse(m_values["Val"]);
    }

    void GetGlonassEphDoubleParamForEachSVResult::setVal(const std::vector<double>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<double>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
