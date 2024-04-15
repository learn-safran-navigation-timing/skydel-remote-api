
#include "GetPseudorangeRampForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRampForSV::CmdName = "GetPseudorangeRampForSV";
    const char* const GetPseudorangeRampForSV::Documentation = "Get PSR ramp event. This function lets user change the pseudorange of any satellite.\n"
      "If SV ID is set to 0, the change is applied to all satellites.\n"
      "\n"
      "          Hold Start Time\n"
      "          |         Hold Stop Time\n"
      "          |         |\n"
      "          ...........\n"
      "         ..         ...\n"
      "        ..            ...\n"
      "  .......               .........> Time\n"
      "        |               |\n"
      "        Start Time      Stop Time\n"
      "\n"
      "\n"
      "Name Type   Description\n"
      "---- ------ -----------------------------------------------------------------\n"
      "Id   string Unique identifier automatically set by simulator if empty string.\n"
      "            The IDs pool is common between all system.";
    const char* const GetPseudorangeRampForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetPseudorangeRampForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeRampForSV);


    GetPseudorangeRampForSV::GetPseudorangeRampForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetPseudorangeRampForSV::GetPseudorangeRampForSV(const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setId(id);
    }

    GetPseudorangeRampForSVPtr GetPseudorangeRampForSV::create(const std::string& id)
    {
      return std::make_shared<GetPseudorangeRampForSV>(id);
    }

    GetPseudorangeRampForSVPtr GetPseudorangeRampForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRampForSV>(ptr);
    }

    bool GetPseudorangeRampForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetPseudorangeRampForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeRampForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Id"}; 
      return names; 
    }


    int GetPseudorangeRampForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeRampForSV::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetPseudorangeRampForSV::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
