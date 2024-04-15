
#include "SetSpoofTxAntenna.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxAntenna::CmdName = "SetSpoofTxAntenna";
    const char* const SetSpoofTxAntenna::Documentation = "Set transmitter antenna pattern.\n"
      "\n"
      "Name Type               Description\n"
      "---- ------------------ -------------------------------------------------------------------------------------------------------------------------\n"
      "Gain array array double Gain matrix (dB). The first dimension will be mapped to elevation [-90, 90] and the second dimension to azimuth [0, 360[.\n"
      "Type AntennaPatternType Pattern type\n"
      "Id   string             Transmitter unique identifier.";
    const char* const SetSpoofTxAntenna::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSpoofTxAntenna);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSpoofTxAntenna);


    SetSpoofTxAntenna::SetSpoofTxAntenna()
      : CommandBase(CmdName, TargetId)
    {}

    SetSpoofTxAntenna::SetSpoofTxAntenna(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }

    SetSpoofTxAntennaPtr SetSpoofTxAntenna::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<SetSpoofTxAntenna>(gain, type, id);
    }

    SetSpoofTxAntennaPtr SetSpoofTxAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSpoofTxAntenna>(ptr);
    }

    bool SetSpoofTxAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetSpoofTxAntenna::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSpoofTxAntenna::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Gain", "Type", "Id"}; 
      return names; 
    }


    int SetSpoofTxAntenna::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetSpoofTxAntenna::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void SetSpoofTxAntenna::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetSpoofTxAntenna::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetSpoofTxAntenna::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetSpoofTxAntenna::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetSpoofTxAntenna::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
