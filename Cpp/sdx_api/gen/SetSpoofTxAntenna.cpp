
#include "gen/SetSpoofTxAntenna.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSpoofTxAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSpoofTxAntenna::CmdName = "SetSpoofTxAntenna";
    const char* const SetSpoofTxAntenna::Documentation = "Set transmitter antenna pattern.";

    REGISTER_COMMAND_FACTORY(SetSpoofTxAntenna);


    SetSpoofTxAntenna::SetSpoofTxAntenna()
      : CommandBase(CmdName)
    {}

    SetSpoofTxAntenna::SetSpoofTxAntenna(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandBase(CmdName)
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
