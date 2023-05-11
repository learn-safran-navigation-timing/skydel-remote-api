
#include "gen/GetPseudorangeNoiseOffsetForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseOffsetForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseOffsetForEachSV::CmdName = "GetPseudorangeNoiseOffsetForEachSV";
    const char* const GetPseudorangeNoiseOffsetForEachSV::Documentation = "Get the satellite pseudorange noise constant offset for all satellites.";

    REGISTER_COMMAND_FACTORY(GetPseudorangeNoiseOffsetForEachSV);


    GetPseudorangeNoiseOffsetForEachSV::GetPseudorangeNoiseOffsetForEachSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeNoiseOffsetForEachSV::GetPseudorangeNoiseOffsetForEachSV(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    GetPseudorangeNoiseOffsetForEachSVPtr GetPseudorangeNoiseOffsetForEachSV::create(const std::string& system)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForEachSV>(system);
    }

    GetPseudorangeNoiseOffsetForEachSVPtr GetPseudorangeNoiseOffsetForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForEachSV>(ptr);
    }

    bool GetPseudorangeNoiseOffsetForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string GetPseudorangeNoiseOffsetForEachSV::documentation() const { return Documentation; }


    int GetPseudorangeNoiseOffsetForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseOffsetForEachSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseOffsetForEachSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
