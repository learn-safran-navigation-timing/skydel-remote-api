
#include "GetGalileoFnavSatelliteK.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFnavSatelliteK
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFnavSatelliteK::CmdName = "GetGalileoFnavSatelliteK";
    const char* const GetGalileoFnavSatelliteK::Documentation = "Get the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).\n"
      "\n"
      "Name Type Description\n"
      "---- ---- --------------------\n"
      "Prn  int  Satellite PRN number";
    const char* const GetGalileoFnavSatelliteK::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetGalileoFnavSatelliteK);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoFnavSatelliteK);


    GetGalileoFnavSatelliteK::GetGalileoFnavSatelliteK()
      : CommandBase(CmdName, TargetId)
    {}

    GetGalileoFnavSatelliteK::GetGalileoFnavSatelliteK(int prn)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& GetGalileoFnavSatelliteK::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Prn"}; 
      return names; 
    }


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
