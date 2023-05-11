
#include "gen/GetSVType.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSVType
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSVType::CmdName = "GetSVType";
    const char* const GetSVType::Documentation = "Get the type of a SV.\nSatellite SV ID accepted values:\nQZSS 1..10";

    REGISTER_COMMAND_FACTORY(GetSVType);


    GetSVType::GetSVType()
      : CommandBase(CmdName)
    {}

    GetSVType::GetSVType(const std::string& system, int svId)
      : CommandBase(CmdName)
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
