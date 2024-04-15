
#include "ForceSpoofTxAttitudeToZero.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of ForceSpoofTxAttitudeToZero
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ForceSpoofTxAttitudeToZero::CmdName = "ForceSpoofTxAttitudeToZero";
    const char* const ForceSpoofTxAttitudeToZero::Documentation = "Set whether the spoofer transmitter vehicle yaw, pitch and roll should be forced to zero.\n"
      "\n"
      "Name    Type   Description\n"
      "------- ------ -------------------------------------------------------------------\n"
      "Enabled bool   If true, spoofer transmitter vehicle won't rotate during simulation\n"
      "Id      string Transmitter unique identifier.";
    const char* const ForceSpoofTxAttitudeToZero::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(ForceSpoofTxAttitudeToZero);
    REGISTER_COMMAND_TO_FACTORY_IMPL(ForceSpoofTxAttitudeToZero);


    ForceSpoofTxAttitudeToZero::ForceSpoofTxAttitudeToZero()
      : CommandBase(CmdName, TargetId)
    {}

    ForceSpoofTxAttitudeToZero::ForceSpoofTxAttitudeToZero(bool enabled, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
      setId(id);
    }

    ForceSpoofTxAttitudeToZeroPtr ForceSpoofTxAttitudeToZero::create(bool enabled, const std::string& id)
    {
      return std::make_shared<ForceSpoofTxAttitudeToZero>(enabled, id);
    }

    ForceSpoofTxAttitudeToZeroPtr ForceSpoofTxAttitudeToZero::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ForceSpoofTxAttitudeToZero>(ptr);
    }

    bool ForceSpoofTxAttitudeToZero::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string ForceSpoofTxAttitudeToZero::documentation() const { return Documentation; }

    const std::vector<std::string>& ForceSpoofTxAttitudeToZero::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled", "Id"}; 
      return names; 
    }


    int ForceSpoofTxAttitudeToZero::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool ForceSpoofTxAttitudeToZero::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void ForceSpoofTxAttitudeToZero::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ForceSpoofTxAttitudeToZero::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void ForceSpoofTxAttitudeToZero::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
