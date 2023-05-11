
#include "gen/IsIntTxTrajectorySmoothingEnabled.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsIntTxTrajectorySmoothingEnabled
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsIntTxTrajectorySmoothingEnabled::CmdName = "IsIntTxTrajectorySmoothingEnabled";
    const char* const IsIntTxTrajectorySmoothingEnabled::Documentation = "Get trajectory smoothing for interference Track enabled or disabled";

    REGISTER_COMMAND_FACTORY(IsIntTxTrajectorySmoothingEnabled);


    IsIntTxTrajectorySmoothingEnabled::IsIntTxTrajectorySmoothingEnabled()
      : CommandBase(CmdName)
    {}

    IsIntTxTrajectorySmoothingEnabled::IsIntTxTrajectorySmoothingEnabled(const std::string& id)
      : CommandBase(CmdName)
    {

      setId(id);
    }

    IsIntTxTrajectorySmoothingEnabledPtr IsIntTxTrajectorySmoothingEnabled::create(const std::string& id)
    {
      return std::make_shared<IsIntTxTrajectorySmoothingEnabled>(id);
    }

    IsIntTxTrajectorySmoothingEnabledPtr IsIntTxTrajectorySmoothingEnabled::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsIntTxTrajectorySmoothingEnabled>(ptr);
    }

    bool IsIntTxTrajectorySmoothingEnabled::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string IsIntTxTrajectorySmoothingEnabled::documentation() const { return Documentation; }


    int IsIntTxTrajectorySmoothingEnabled::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsIntTxTrajectorySmoothingEnabled::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void IsIntTxTrajectorySmoothingEnabled::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
