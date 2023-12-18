
#include "gen/PushDynamicAlmanacData.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of PushDynamicAlmanacData
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const PushDynamicAlmanacData::CmdName = "PushDynamicAlmanacData";
    const char* const PushDynamicAlmanacData::Documentation = "Push a block of data defining the orbit, clock, and other parameters for one SV.\n  ParamName           Unit\n  \"Time of ephemeris\" sec (of GPS week)\n  \"Week Number\"       week\n  \"Transmission Time\" sec (of GPS week)\n  \"ClockBias\"         sec\n  \"ClockDrift\"        sec/sec\n  \"ClockDriftRate\"    sec/sec^2\n  \"DeltaN\"            rad/sec\n  \"M0\"                rad\n  \"Eccentricity\"      -\n  \"SqrtA\"             sqrt(meter)\n  \"BigOmega\"          rad\n  \"I0\"                rad\n  \"LittleOmega\"       rad\n  \"BigOmegaDot\"       rad/sec\n  \"Idot\"              rad/sec";

    REGISTER_COMMAND_FACTORY(PushDynamicAlmanacData);


    PushDynamicAlmanacData::PushDynamicAlmanacData()
      : CommandBase(CmdName)
    {}

    PushDynamicAlmanacData::PushDynamicAlmanacData(const std::string& system, const Sdx::DateTime& toa, const std::vector<Sdx::AlmanacSVData>& almanac)
      : CommandBase(CmdName)
    {

      setSystem(system);
      setToa(toa);
      setAlmanac(almanac);
    }

    PushDynamicAlmanacDataPtr PushDynamicAlmanacData::create(const std::string& system, const Sdx::DateTime& toa, const std::vector<Sdx::AlmanacSVData>& almanac)
    {
      return std::make_shared<PushDynamicAlmanacData>(system, toa, almanac);
    }

    PushDynamicAlmanacDataPtr PushDynamicAlmanacData::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<PushDynamicAlmanacData>(ptr);
    }

    bool PushDynamicAlmanacData::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<Sdx::DateTime>::is_valid(m_values["Toa"])
          && parse_json<std::vector<Sdx::AlmanacSVData>>::is_valid(m_values["Almanac"])
        ;

    }

    std::string PushDynamicAlmanacData::documentation() const { return Documentation; }


    int PushDynamicAlmanacData::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string PushDynamicAlmanacData::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void PushDynamicAlmanacData::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::DateTime PushDynamicAlmanacData::toa() const
    {
      return parse_json<Sdx::DateTime>::parse(m_values["Toa"]);
    }

    void PushDynamicAlmanacData::setToa(const Sdx::DateTime& toa)
    {
      m_values.AddMember("Toa", parse_json<Sdx::DateTime>::format(toa, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::vector<Sdx::AlmanacSVData> PushDynamicAlmanacData::almanac() const
    {
      return parse_json<std::vector<Sdx::AlmanacSVData>>::parse(m_values["Almanac"]);
    }

    void PushDynamicAlmanacData::setAlmanac(const std::vector<Sdx::AlmanacSVData>& almanac)
    {
      m_values.AddMember("Almanac", parse_json<std::vector<Sdx::AlmanacSVData>>::format(almanac, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
