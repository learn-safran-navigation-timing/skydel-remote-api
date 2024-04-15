
#include "SetIntTxIgnorePropagationLoss.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIntTxIgnorePropagationLoss
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIntTxIgnorePropagationLoss::CmdName = "SetIntTxIgnorePropagationLoss";
    const char* const SetIntTxIgnorePropagationLoss::Documentation = "Set whether a dynamic transmitter should ignore propagation loss or not.\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ ------------------------------------------\n"
      "Ignore bool   If true, propagation loss will be ignored.\n"
      "Id     string Transmitter unique identifier.";
    const char* const SetIntTxIgnorePropagationLoss::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIntTxIgnorePropagationLoss);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIntTxIgnorePropagationLoss);


    SetIntTxIgnorePropagationLoss::SetIntTxIgnorePropagationLoss()
      : CommandBase(CmdName, TargetId)
    {}

    SetIntTxIgnorePropagationLoss::SetIntTxIgnorePropagationLoss(bool ignore, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setIgnore(ignore);
      setId(id);
    }

    SetIntTxIgnorePropagationLossPtr SetIntTxIgnorePropagationLoss::create(bool ignore, const std::string& id)
    {
      return std::make_shared<SetIntTxIgnorePropagationLoss>(ignore, id);
    }

    SetIntTxIgnorePropagationLossPtr SetIntTxIgnorePropagationLoss::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIntTxIgnorePropagationLoss>(ptr);
    }

    bool SetIntTxIgnorePropagationLoss::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Ignore"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetIntTxIgnorePropagationLoss::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIntTxIgnorePropagationLoss::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Ignore", "Id"}; 
      return names; 
    }


    int SetIntTxIgnorePropagationLoss::executePermission() const
    {
      return EXECUTE_IF_SIMULATING | EXECUTE_IF_IDLE;
    }


    bool SetIntTxIgnorePropagationLoss::ignore() const
    {
      return parse_json<bool>::parse(m_values["Ignore"]);
    }

    void SetIntTxIgnorePropagationLoss::setIgnore(bool ignore)
    {
      m_values.AddMember("Ignore", parse_json<bool>::format(ignore, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetIntTxIgnorePropagationLoss::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetIntTxIgnorePropagationLoss::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
