
#include "gen/GetPseudorangeNoiseOffsetForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeNoiseOffsetForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeNoiseOffsetForSV::CmdName = "GetPseudorangeNoiseOffsetForSV";
    const char* const GetPseudorangeNoiseOffsetForSV::Documentation = "Get the satellite pseudorange noise constant offset.";

    REGISTER_COMMAND_FACTORY(GetPseudorangeNoiseOffsetForSV);


    GetPseudorangeNoiseOffsetForSV::GetPseudorangeNoiseOffsetForSV()
      : CommandBase(CmdName)
    {}

    GetPseudorangeNoiseOffsetForSV::GetPseudorangeNoiseOffsetForSV(const std::string& system, int svId)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetPseudorangeNoiseOffsetForSVPtr GetPseudorangeNoiseOffsetForSV::create(const std::string& system, int svId)
    {
      return std::make_shared<GetPseudorangeNoiseOffsetForSV>(system, svId);
    }

    GetPseudorangeNoiseOffsetForSVPtr GetPseudorangeNoiseOffsetForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeNoiseOffsetForSV>(ptr);
    }

    bool GetPseudorangeNoiseOffsetForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetPseudorangeNoiseOffsetForSV::documentation() const { return Documentation; }


    int GetPseudorangeNoiseOffsetForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetPseudorangeNoiseOffsetForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeNoiseOffsetForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeNoiseOffsetForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeNoiseOffsetForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
