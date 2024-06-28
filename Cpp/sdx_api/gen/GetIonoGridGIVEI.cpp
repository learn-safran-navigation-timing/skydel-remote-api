
#include "GetIonoGridGIVEI.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEI::CmdName = "GetIonoGridGIVEI";
    const char* const GetIonoGridGIVEI::Documentation = "Get the GIVEI for a ionospheric grid point\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- -------------------------------\n"
      "Band            int             The ionospheric grid band index\n"
      "Point           int             The IGP index\n"
      "ServiceProvider optional string The service provider (optional)";
    const char* const GetIonoGridGIVEI::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(GetIonoGridGIVEI);
    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridGIVEI);


    GetIonoGridGIVEI::GetIonoGridGIVEI()
      : CommandBase(CmdName, TargetId)
    {}

    GetIonoGridGIVEI::GetIonoGridGIVEI(int band, int point, const std::optional<std::string>& serviceProvider)
      : CommandBase(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIPtr GetIonoGridGIVEI::create(int band, int point, const std::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEI>(band, point, serviceProvider);
    }

    GetIonoGridGIVEIPtr GetIonoGridGIVEI::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridGIVEI>(ptr);
    }

    bool GetIonoGridGIVEI::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<std::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEI::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridGIVEI::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point", "ServiceProvider"}; 
      return names; 
    }


    int GetIonoGridGIVEI::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int GetIonoGridGIVEI::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridGIVEI::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridGIVEI::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridGIVEI::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::optional<std::string> GetIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<std::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEI::setServiceProvider(const std::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
