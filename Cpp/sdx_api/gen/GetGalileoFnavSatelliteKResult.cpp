
#include "GetGalileoFnavSatelliteKResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetGalileoFnavSatelliteKResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetGalileoFnavSatelliteKResult::CmdName = "GetGalileoFnavSatelliteKResult";
    const char* const GetGalileoFnavSatelliteKResult::Documentation = "Result of GetGalileoFnavSatelliteK.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------\n"
      "Prn  int  Satellite PRN number\n"
      "K    int  Satellite K PRN number.";
    const char* const GetGalileoFnavSatelliteKResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetGalileoFnavSatelliteKResult);


    GetGalileoFnavSatelliteKResult::GetGalileoFnavSatelliteKResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetGalileoFnavSatelliteKResult::GetGalileoFnavSatelliteKResult(int prn, int k)
      : CommandResult(CmdName, TargetId)
    {

      setPrn(prn);
      setK(k);
    }

    GetGalileoFnavSatelliteKResult::GetGalileoFnavSatelliteKResult(CommandBasePtr relatedCommand, int prn, int k)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setPrn(prn);
      setK(k);
    }


    GetGalileoFnavSatelliteKResultPtr GetGalileoFnavSatelliteKResult::create(int prn, int k)
    {
      return std::make_shared<GetGalileoFnavSatelliteKResult>(prn, k);
    }

    GetGalileoFnavSatelliteKResultPtr GetGalileoFnavSatelliteKResult::create(CommandBasePtr relatedCommand, int prn, int k)
    {
      return std::make_shared<GetGalileoFnavSatelliteKResult>(relatedCommand, prn, k);
    }

    GetGalileoFnavSatelliteKResultPtr GetGalileoFnavSatelliteKResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetGalileoFnavSatelliteKResult>(ptr);
    }

    bool GetGalileoFnavSatelliteKResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Prn"])
          && parse_json<int>::is_valid(m_values["K"])
        ;

    }

    std::string GetGalileoFnavSatelliteKResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetGalileoFnavSatelliteKResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Prn", "K"}; 
      return names; 
    }


    int GetGalileoFnavSatelliteKResult::prn() const
    {
      return parse_json<int>::parse(m_values["Prn"]);
    }

    void GetGalileoFnavSatelliteKResult::setPrn(int prn)
    {
      m_values.AddMember("Prn", parse_json<int>::format(prn, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetGalileoFnavSatelliteKResult::k() const
    {
      return parse_json<int>::parse(m_values["K"]);
    }

    void GetGalileoFnavSatelliteKResult::setK(int k)
    {
      m_values.AddMember("K", parse_json<int>::format(k, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
