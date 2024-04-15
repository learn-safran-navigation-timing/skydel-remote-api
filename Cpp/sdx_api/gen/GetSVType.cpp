
#include "GetSVType.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVType::CmdName = "GetSVType";
    const char* const GetSVType::Documentation = "Get the type of a SV.\n"
      "Satellite SV ID accepted values:\n"
      "QZSS 1..10\n"
      "\n"
      "Name   Type   Description\n"
      "------ ------ -------------------------------------------------------------\n"
      "System string Only \"QZSS\" supported.\n"
      "SvId   int    Satellite SV ID, see command description for accepted values.";
    const char* const GetSVType::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetSVType);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSVType);


    GetSVType::GetSVType()
      : CommandBase(CmdName, TargetId)
    {}

    GetSVType::GetSVType(const std::string& system, int svId)
      : CommandBase(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
    }

    GetSVTypePtr GetSVType::create(const std::string& system, int svId)
    {
      return std::make_shared<GetSVType>(system, svId);
    }

    GetSVTypePtr GetSVType::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSVType>(ptr);
    }

    bool GetSVType::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string GetSVType::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSVType::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId"}; 
      return names; 
    }


    int GetSVType::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetSVType::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetSVType::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSVType::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetSVType::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
