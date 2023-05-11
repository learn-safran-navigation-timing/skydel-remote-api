
#include "gen/GetGalileoFnavSatelliteK.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFnavSatelliteK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFnavSatelliteK::CmdName = "GetGalileoFnavSatelliteK";
    const char* const GetGalileoFnavSatelliteK::Documentation = "Get the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).";

    REGISTER_COMMAND_FACTORY(GetGalileoFnavSatelliteK);


    GetGalileoFnavSatelliteK::GetGalileoFnavSatelliteK()
      : CommandBase(CmdName)
    {}

    GetGalileoFnavSatelliteK::GetGalileoFnavSatelliteK(int prn)
      : CommandBase(CmdName)
    {

      setPrn(prn);
    }

    GetGalileoFnavSatelliteKPtr GetGalileoFnavSatelliteK::create(int prn)
    {
      return std::make_shared<GetGalileoFnavSatelliteK>(prn);
    }

    GetGalileoFnavSatelliteKPtr GetGalileoFnavSatelliteK::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFnavSatelliteK>(ptr);
    }

    bool GetGalileoFnavSatelliteK::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
        ;

    }

    std::string GetGalileoFnavSatelliteK::documentation() const { return Documentation; }


    int GetGalileoFnavSatelliteK::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetGalileoFnavSatelliteK::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoFnavSatelliteK::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
