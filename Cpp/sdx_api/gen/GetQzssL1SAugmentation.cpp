
#include "GetQzssL1SAugmentation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetQzssL1SAugmentation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetQzssL1SAugmentation::CmdName = "GetQzssL1SAugmentation";
    const char* const GetQzssL1SAugmentation::Documentation = "Get Add an augmentation to the L1S navigation messages.\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ --------------------------------------\n"
      "Id   string Unique identifier of the augmentation.";
    const char* const GetQzssL1SAugmentation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1SAugmentation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetQzssL1SAugmentation);


    GetQzssL1SAugmentation::GetQzssL1SAugmentation()
      : CommandBase(CmdName, TargetId)
    {}

    GetQzssL1SAugmentation::GetQzssL1SAugmentation(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetQzssL1SAugmentationPtr GetQzssL1SAugmentation::create(const std::string& id)
    {
      return std::make_shared<GetQzssL1SAugmentation>(id);
    }

    GetQzssL1SAugmentationPtr GetQzssL1SAugmentation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetQzssL1SAugmentation>(ptr);
    }

    bool GetQzssL1SAugmentation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetQzssL1SAugmentation::documentation() const { return Documentation; }

    const std::vector<std::string>& GetQzssL1SAugmentation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetQzssL1SAugmentation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetQzssL1SAugmentation::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetQzssL1SAugmentation::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
