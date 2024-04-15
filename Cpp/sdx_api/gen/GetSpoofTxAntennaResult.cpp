
#include "GetSpoofTxAntennaResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxAntennaResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxAntennaResult::CmdName = "GetSpoofTxAntennaResult";
    const char* const GetSpoofTxAntennaResult::Documentation = "Result of GetSpoofTxAntenna.\n"
      "\n"
      "Name Type               Description\n"
      "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"
      "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
      "Type AntennaPatternType Pattern type\n"
      "Id   string             Transmitter unique identifier.";
    const char* const GetSpoofTxAntennaResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSpoofTxAntennaResult);


    GetSpoofTxAntennaResult::GetSpoofTxAntennaResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSpoofTxAntennaResult::GetSpoofTxAntennaResult(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }

    GetSpoofTxAntennaResult::GetSpoofTxAntennaResult(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }


    GetSpoofTxAntennaResultPtr GetSpoofTxAntennaResult::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<GetSpoofTxAntennaResult>(gain, type, id);
    }

    GetSpoofTxAntennaResultPtr GetSpoofTxAntennaResult::create(CommandBasePtr relatedCommand, const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<GetSpoofTxAntennaResult>(relatedCommand, gain, type, id);
    }

    GetSpoofTxAntennaResultPtr GetSpoofTxAntennaResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxAntennaResult>(ptr);
    }

    bool GetSpoofTxAntennaResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxAntennaResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSpoofTxAntennaResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Gain", "Type", "Id"}; 
      return names; 
    }


    std::vector<std::vector<double>> GetSpoofTxAntennaResult::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void GetSpoofTxAntennaResult::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType GetSpoofTxAntennaResult::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void GetSpoofTxAntennaResult::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxAntennaResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxAntennaResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
