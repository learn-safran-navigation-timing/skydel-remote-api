
#include "Resume.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of Resume
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const Resume::CmdName = "Resume";
    const char* const Resume::Documentation = "Resume vehicle motion during simulation.";
    const char* const Resume::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(Resume);
    REGISTER_COMMAND_TO_FACTORY_IMPL(Resume);


    Resume::Resume()
      : CommandBase(CmdName, TargetId)
    {

    }

    ResumePtr Resume::create()
    {
      return std::make_shared<Resume>();
    }

    ResumePtr Resume::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<Resume>(ptr);
    }

    bool Resume::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string Resume::documentation() const { return Documentation; }

    const std::vector<std::string>& Resume::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int Resume::executePermission() const
    {
      return EXECUTE_IF_SIMULATING;
    }

  }
}
