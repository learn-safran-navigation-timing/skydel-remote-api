
#include "gen/SetIntTxAntenna.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxAntenna
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxAntenna::CmdName = "SetIntTxAntenna";
    const char* const SetIntTxAntenna::Documentation = "Set transmitter antenna pattern.";

    REGISTER_COMMAND_FACTORY(SetIntTxAntenna);


    SetIntTxAntenna::SetIntTxAntenna()
      : CommandBase(CmdName)
    {}

    SetIntTxAntenna::SetIntTxAntenna(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
      : CommandBase(CmdName)
    {

      setGain(gain);
      setType(type);
      setId(id);
    }

    SetIntTxAntennaPtr SetIntTxAntenna::create(const std::vector<std::vector<double>>& gain, const Sdx::AntennaPatternType& type, const std::string& id)
    {
      return std::make_shared<SetIntTxAntenna>(gain, type, id);
    }

    SetIntTxAntennaPtr SetIntTxAntenna::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxAntenna>(ptr);
    }

    bool SetIntTxAntenna::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::vector<std::vector<double>>>::is_valid(m_values["Gain"])
          && parse_json<Sdx::AntennaPatternType>::is_valid(m_values["Type"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxAntenna::documentation() const { return Documentation; }


    int SetIntTxAntenna::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    std::vector<std::vector<double>> SetIntTxAntenna::gain() const
    {
      return parse_json<std::vector<std::vector<double>>>::parse(m_values["Gain"]);
    }

    void SetIntTxAntenna::setGain(const std::vector<std::vector<double>>& gain)
    {
      m_values.AddMember("Gain", parse_json<std::vector<std::vector<double>>>::format(gain, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::AntennaPatternType SetIntTxAntenna::type() const
    {
      return parse_json<Sdx::AntennaPatternType>::parse(m_values["Type"]);
    }

    void SetIntTxAntenna::setType(const Sdx::AntennaPatternType& type)
    {
      m_values.AddMember("Type", parse_json<Sdx::AntennaPatternType>::format(type, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxAntenna::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxAntenna::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
