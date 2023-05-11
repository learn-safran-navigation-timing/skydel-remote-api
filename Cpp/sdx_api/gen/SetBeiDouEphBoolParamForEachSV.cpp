
#include "gen/SetBeiDouEphBoolParamForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetBeiDouEphBoolParamForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetBeiDouEphBoolParamForEachSV::CmdName = "SetBeiDouEphBoolParamForEachSV";
    const char* const SetBeiDouEphBoolParamForEachSV::Documentation = "Set BeiDou ephemeris boolean parameter value for all satellites";

    REGISTER_COMMAND_FACTORY(SetBeiDouEphBoolParamForEachSV);


    SetBeiDouEphBoolParamForEachSV::SetBeiDouEphBoolParamForEachSV()
      : CommandBase(CmdName)
    {}

    SetBeiDouEphBoolParamForEachSV::SetBeiDouEphBoolParamForEachSV(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setParamName(paramName);
      setVal(val);
      setDataSetName(dataSetName);
    }

    SetBeiDouEphBoolParamForEachSVPtr SetBeiDouEphBoolParamForEachSV::create(const std::string& paramName, const std::vector<bool>& val, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<SetBeiDouEphBoolParamForEachSV>(paramName, val, dataSetName);
    }

    SetBeiDouEphBoolParamForEachSVPtr SetBeiDouEphBoolParamForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetBeiDouEphBoolParamForEachSV>(ptr);
    }

    bool SetBeiDouEphBoolParamForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ParamName"])
          && parse_json<std::vector<bool>>::is_valid(m_values["Val"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string SetBeiDouEphBoolParamForEachSV::documentation() const { return Documentation; }


    int SetBeiDouEphBoolParamForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string SetBeiDouEphBoolParamForEachSV::paramName() const
    {
      return parse_json<std::string>::parse(m_values["ParamName"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setParamName(const std::string& paramName)
    {
      m_values.AddMember("ParamName", parse_json<std::string>::format(paramName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<bool> SetBeiDouEphBoolParamForEachSV::val() const
    {
      return parse_json<std::vector<bool>>::parse(m_values["Val"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setVal(const std::vector<bool>& val)
    {
      m_values.AddMember("Val", parse_json<std::vector<bool>>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> SetBeiDouEphBoolParamForEachSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void SetBeiDouEphBoolParamForEachSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
