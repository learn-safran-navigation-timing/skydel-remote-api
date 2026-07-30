
#include "EnableGnssSignalTerrainObscuration.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableGnssSignalTerrainObscuration
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableGnssSignalTerrainObscuration::CmdName = "EnableGnssSignalTerrainObscuration";
    const char* const EnableGnssSignalTerrainObscuration::Documentation = "Enable (or disable) GNSS signals obscuration by terrain.\n"
      "\n"
      "Name    Type Description\n"
      "------- ---- --------------------------------------------------------------------------------------\n"
      "Enabled bool If true, GNSS signals from satellites obscured by terrain will not reach the receiver.";
    const char* const EnableGnssSignalTerrainObscuration::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableGnssSignalTerrainObscuration);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableGnssSignalTerrainObscuration);


    EnableGnssSignalTerrainObscuration::EnableGnssSignalTerrainObscuration()
      : CommandBase(CmdName, TargetId)
    {}

    EnableGnssSignalTerrainObscuration::EnableGnssSignalTerrainObscuration(bool enabled)
      : CommandBase(CmdName, TargetId)
    {

      setEnabled(enabled);
    }

    EnableGnssSignalTerrainObscurationPtr EnableGnssSignalTerrainObscuration::create(bool enabled)
    {
      return std::make_shared<EnableGnssSignalTerrainObscuration>(enabled);
    }

    EnableGnssSignalTerrainObscurationPtr EnableGnssSignalTerrainObscuration::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableGnssSignalTerrainObscuration>(ptr);
    }

    bool EnableGnssSignalTerrainObscuration::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enabled"])
        ;

    }

    std::string EnableGnssSignalTerrainObscuration::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableGnssSignalTerrainObscuration::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enabled"}; 
      return names; 
    }


    int EnableGnssSignalTerrainObscuration::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableGnssSignalTerrainObscuration::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void EnableGnssSignalTerrainObscuration::setEnabled(bool enabled)
    {
      setValue("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()));
    }


  }
}
