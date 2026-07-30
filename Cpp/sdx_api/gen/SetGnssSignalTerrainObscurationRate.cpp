
#include "SetGnssSignalTerrainObscurationRate.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetGnssSignalTerrainObscurationRate
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetGnssSignalTerrainObscurationRate::CmdName = "SetGnssSignalTerrainObscurationRate";
    const char* const SetGnssSignalTerrainObscurationRate::Documentation = "Set the rate (in Hz) at which line-of-sight between the receiver and satellites is evaluated for terrain obscuration.\n"
      "\n"
      "Name Type Description\n"
      "---- ---- -----------------------------------------------------------------------------------------------------------------------------------------------------\n"
      "Rate int  Rate at which line-of-sight between the receiver and satellites is evaluated. Accepted values are: 1 Hz, 5 Hz, 10 Hz, 20 Hz, 25 Hz, 40 Hz, and 50 Hz.";
    const char* const SetGnssSignalTerrainObscurationRate::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetGnssSignalTerrainObscurationRate);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetGnssSignalTerrainObscurationRate);


    SetGnssSignalTerrainObscurationRate::SetGnssSignalTerrainObscurationRate()
      : CommandBase(CmdName, TargetId)
    {}

    SetGnssSignalTerrainObscurationRate::SetGnssSignalTerrainObscurationRate(int rate)
      : CommandBase(CmdName, TargetId)
    {

      setRate(rate);
    }

    SetGnssSignalTerrainObscurationRatePtr SetGnssSignalTerrainObscurationRate::create(int rate)
    {
      return std::make_shared<SetGnssSignalTerrainObscurationRate>(rate);
    }

    SetGnssSignalTerrainObscurationRatePtr SetGnssSignalTerrainObscurationRate::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetGnssSignalTerrainObscurationRate>(ptr);
    }

    bool SetGnssSignalTerrainObscurationRate::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Rate"])
        ;

    }

    std::string SetGnssSignalTerrainObscurationRate::documentation() const { return Documentation; }

    const std::vector<std::string>& SetGnssSignalTerrainObscurationRate::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Rate"}; 
      return names; 
    }


    int SetGnssSignalTerrainObscurationRate::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetGnssSignalTerrainObscurationRate::rate() const
    {
      return parse_json<int>::parse(m_values["Rate"]);
    }

    void SetGnssSignalTerrainObscurationRate::setRate(int rate)
    {
      setValue("Rate", parse_json<int>::format(rate, m_values.GetAllocator()));
    }


  }
}
