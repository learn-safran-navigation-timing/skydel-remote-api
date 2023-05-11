
#include "gen/GetQzssEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssEphBoolParamForEachSV::CmdName = "GetQzssEphBoolParamForEachSV";
    const char* const GetQzssEphBoolParamForEachSV::Documentation = "Get QZSS ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(GetQzssEphBoolParamForEachSV);


    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    GetQzssEphBoolParamForEachSV::GetQzssEphBoolParamForEachSV(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setDataSetName(dataSetName);
    }

    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::create(const std::string& paramName, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetQzssEphBoolParamForEachSV>(paramName, dataSetName);
    }

    GetQzssEphBoolParamForEachSVPtr GetQzssEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssEphBoolParamForEachSV>(ptr);
    }

    bool GetQzssEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetQzssEphBoolParamForEachSV::documentation() const { return Documentation; }


    int GetQzssEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void GetQzssEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetQzssEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetQzssEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
