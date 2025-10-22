
#include "GetSbasServiceProviderForEachSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSbasServiceProviderForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSbasServiceProviderForEachSV::CmdName = "GetSbasServiceProviderForEachSV";
    const char* const GetSbasServiceProviderForEachSV::Documentation = "Get the service provider of all the SBAS satellites.";
    const char* const GetSbasServiceProviderForEachSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasServiceProviderForEachSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSbasServiceProviderForEachSV);


    GetSbasServiceProviderForEachSV::GetSbasServiceProviderForEachSV()
      : CommandBase(CmdName, TargetId)
    {

    }

    GetSbasServiceProviderForEachSVPtr GetSbasServiceProviderForEachSV::create()
    {
      return std::make_shared<GetSbasServiceProviderForEachSV>();
    }

    GetSbasServiceProviderForEachSVPtr GetSbasServiceProviderForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSbasServiceProviderForEachSV>(ptr);
    }

    bool GetSbasServiceProviderForEachSV::isValid() const
    {
      
        return m_values.IsObject()
        ;

    }

    std::string GetSbasServiceProviderForEachSV::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSbasServiceProviderForEachSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {}; 
      return names; 
    }


    int GetSbasServiceProviderForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }

  }
}
