
#include "IsSpoofTxTrajectorySmoothingEnabled.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSpoofTxTrajectorySmoothingEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSpoofTxTrajectorySmoothingEnabled::CmdName = "IsSpoofTxTrajectorySmoothingEnabled";
    const char* const IsSpoofTxTrajectorySmoothingEnabled::Documentation = "Get trajectory smoothing for spoofer transmitter Track enabled or disabled\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ------------------------------\n"
      "Id   string Transmitter unique identifier.";
    const char* const IsSpoofTxTrajectorySmoothingEnabled::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxTrajectorySmoothingEnabled);
    REGISTER_COMMAND_TO_FACTORY_IMPL(IsSpoofTxTrajectorySmoothingEnabled);


    IsSpoofTxTrajectorySmoothingEnabled::IsSpoofTxTrajectorySmoothingEnabled()
      : CommandBase(CmdName, TargetId)
    {}

    IsSpoofTxTrajectorySmoothingEnabled::IsSpoofTxTrajectorySmoothingEnabled(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    IsSpoofTxTrajectorySmoothingEnabledPtr IsSpoofTxTrajectorySmoothingEnabled::create(const std::string& id)
    {
      return std::make_shared<IsSpoofTxTrajectorySmoothingEnabled>(id);
    }

    IsSpoofTxTrajectorySmoothingEnabledPtr IsSpoofTxTrajectorySmoothingEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSpoofTxTrajectorySmoothingEnabled>(ptr);
    }

    bool IsSpoofTxTrajectorySmoothingEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsSpoofTxTrajectorySmoothingEnabled::documentation() const { return Documentation; }

    const std::vector<std::string>& IsSpoofTxTrajectorySmoothingEnabled::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int IsSpoofTxTrajectorySmoothingEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSpoofTxTrajectorySmoothingEnabled::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsSpoofTxTrajectorySmoothingEnabled::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
