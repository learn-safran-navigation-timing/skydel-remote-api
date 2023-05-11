
#include "gen/GetIntTxAntennaResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxAntennaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxAntennaResult::CmdName = "GetIntTxAntennaResult";
    const char* const GetIntTxAntennaResult::Documentation = "Result of GetIntTxAntenna.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxAntennaResult);


    GetIntTxAntennaResult::GetIntTxAntennaResult()
      : CommandResult(CmdName)
    {}

    GetIntTxAntennaResult::GetIntTxAntennaResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandResult(CmdName)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }

    GetIntTxAntennaResult::GetIntTxAntennaResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }


    GetIntTxAntennaResultPtr GetIntTxAntennaResult::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<GetIntTxAntennaResult>(gain, type, id);
    }

    GetIntTxAntennaResultPtr GetIntTxAntennaResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<GetIntTxAntennaResult>(relatedCommand, gain, type, id);
    }

    GetIntTxAntennaResultPtr GetIntTxAntennaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxAntennaResult>(ptr);
    }

    bool GetIntTxAntennaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxAntennaResult::documentation() const { return Documentation; }


    std::vector<std::vector<double>> GetIntTxAntennaResult::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void GetIntTxAntennaResult::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetIntTxAntennaResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetIntTxAntennaResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxAntennaResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxAntennaResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
