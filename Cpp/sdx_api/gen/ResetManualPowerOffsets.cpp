
#include "gen/ResetManualPowerOffsets.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ResetManualPowerOffsets
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ResetManualPowerOffsets::CmdName = "ResetManualPowerOffsets";
    const char* const ResetManualPowerOffsets::Documentation = "Reset power offset for all satellites is specified system to default value";

    REGISTER_COMMAND_FACTORY(ResetManualPowerOffsets);


    ResetManualPowerOffsets::ResetManualPowerOffsets()
      : CommandBase(CmdName)
    {}

    ResetManualPowerOffsets::ResetManualPowerOffsets(const std::string& system)
      : CommandBase(CmdName)
    {

      setSystem(system);
    }

    ResetManualPowerOffsetsPtr ResetManualPowerOffsets::create(const std::string& system)
    {
      return std::make_shared<ResetManualPowerOffsets>(system);
    }

    ResetManualPowerOffsetsPtr ResetManualPowerOffsets::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ResetManualPowerOffsets>(ptr);
    }

    bool ResetManualPowerOffsets::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
        ;

    }

    std::string ResetManualPowerOffsets::documentation() const { return Documentation; }


    int ResetManualPowerOffsets::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }


    std::string ResetManualPowerOffsets::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void ResetManualPowerOffsets::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
