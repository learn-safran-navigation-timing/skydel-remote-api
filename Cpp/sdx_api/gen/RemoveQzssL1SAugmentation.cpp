
#include "RemoveQzssL1SAugmentation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of RemoveQzssL1SAugmentation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const RemoveQzssL1SAugmentation::CmdName = "RemoveQzssL1SAugmentation";
    const char* const RemoveQzssL1SAugmentation::Documentation = "Removes a QZSS L1S augmentation.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ ----------------------------------------------\n"
      "Id   string Unique identifier (see SetQzssL1SAugmentation)";
    const char* const RemoveQzssL1SAugmentation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(RemoveQzssL1SAugmentation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(RemoveQzssL1SAugmentation);


    RemoveQzssL1SAugmentation::RemoveQzssL1SAugmentation()
      : CommandBase(CmdName, TargetId)
    {}

    RemoveQzssL1SAugmentation::RemoveQzssL1SAugmentation(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    RemoveQzssL1SAugmentationPtr RemoveQzssL1SAugmentation::create(const std::string& id)
    {
      return std::make_shared<RemoveQzssL1SAugmentation>(id);
    }

    RemoveQzssL1SAugmentationPtr RemoveQzssL1SAugmentation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<RemoveQzssL1SAugmentation>(ptr);
    }

    bool RemoveQzssL1SAugmentation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string RemoveQzssL1SAugmentation::documentation() const { return Documentation; }

    const std::vector<std::string>& RemoveQzssL1SAugmentation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int RemoveQzssL1SAugmentation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string RemoveQzssL1SAugmentation::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void RemoveQzssL1SAugmentation::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
