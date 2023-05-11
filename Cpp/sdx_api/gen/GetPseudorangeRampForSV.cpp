
#include "gen/GetPseudorangeRampForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRampForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRampForSV::CmdName = "GetPseudorangeRampForSV";
    const char* const GetPseudorangeRampForSV::Documentation = "Get PSR ramp event. This function lets user change the pseudorange of any satellite.\nIf SV ID is set to 0, the change is applied to all satellites.\n\n          Hold Start Time\n          |         Hold Stop Time\n          |         |\n          ...........\n         ..         ...\n        ..            ...\n  .......               .........> Time\n        |               |\n        Start Time      Stop Time\n";

    REGISTER_COMMAND_FACTORY(GetPseudorangeRampForSV);


    GetPseudorangeRampForSV::GetPseudorangeRampForSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeRampForSV::GetPseudorangeRampForSV(const std::string& id)
      : CommandBase(CmdName)
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
