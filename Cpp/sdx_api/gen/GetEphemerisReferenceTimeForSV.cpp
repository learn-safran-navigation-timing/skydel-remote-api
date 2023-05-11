
#include "gen/GetEphemerisReferenceTimeForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetEphemerisReferenceTimeForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetEphemerisReferenceTimeForSV::CmdName = "GetEphemerisReferenceTimeForSV";
    const char* const GetEphemerisReferenceTimeForSV::Documentation = "Get the ephemeris reference time for the specified constellation.";

    REGISTER_COMMAND_FACTORY(GetEphemerisReferenceTimeForSV);


    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV()
      : CommandBase(CmdName)
    {}

    GetEphemerisReferenceTimeForSV::GetEphemerisReferenceTimeForSV(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setSvId(svId);
      setDataSetName(dataSetName);
    }

    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::create(const std::string& system, int svId, const Sdx::optional<std::string>& dataSetName)
    {
      return std::make_shared<GetEphemerisReferenceTimeForSV>(system, svId, dataSetName);
    }

    GetEphemerisReferenceTimeForSVPtr GetEphemerisReferenceTimeForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetEphemerisReferenceTimeForSV>(ptr);
    }

    bool GetEphemerisReferenceTimeForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["DataSetName"])
        ;

    }

    std::string GetEphemerisReferenceTimeForSV::documentation() const { return Documentation; }


    int GetEphemerisReferenceTimeForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetEphemerisReferenceTimeForSV::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetEphemerisReferenceTimeForSV::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetEphemerisReferenceTimeForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetEphemerisReferenceTimeForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetEphemerisReferenceTimeForSV::dataSetName() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["DataSetName"]);
    }

    void GetEphemerisReferenceTimeForSV::setDataSetName(const Sdx::optional<std::string>& dataSetName)
    {
      m_values.AddMember("DataSetName", parse_json<Sdx::optional<std::string>>::format(dataSetName, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
