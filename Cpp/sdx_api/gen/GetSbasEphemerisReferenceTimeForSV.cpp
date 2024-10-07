
#include "GetSbasEphemerisReferenceTimeForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasEphemerisReferenceTimeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasEphemerisReferenceTimeForSV::CmdName = "GetSbasEphemerisReferenceTimeForSV";
    const char* const GetSbasEphemerisReferenceTimeForSV::Documentation = "Get the ephemeris reference time for a SBAS satellite.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- ----------------------\n"
      "SvId int  The satellite's SV ID.";
    const char* const GetSbasEphemerisReferenceTimeForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasEphemerisReferenceTimeForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasEphemerisReferenceTimeForSV);


    GetSbasEphemerisReferenceTimeForSV::GetSbasEphemerisReferenceTimeForSV()
      : CommandBase(CmdName, TargetId)
    {}

    GetSbasEphemerisReferenceTimeForSV::GetSbasEphemerisReferenceTimeForSV(int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSvId(svId);
    }

    GetSbasEphemerisReferenceTimeForSVPtr GetSbasEphemerisReferenceTimeForSV::create(int svId)
    {
      return std::make_shared<GetSbasEphemerisReferenceTimeForSV>(svId);
    }

    GetSbasEphemerisReferenceTimeForSVPtr GetSbasEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasEphemerisReferenceTimeForSV>(ptr);
    }

    bool GetSbasEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetSbasEphemerisReferenceTimeForSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasEphemerisReferenceTimeForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId"}; 
      return names; 
    }


    int GetSbasEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetSbasEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSbasEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
