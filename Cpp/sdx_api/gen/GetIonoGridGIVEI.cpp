
#include "gen/GetIonoGridGIVEI.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEI
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEI::CmdName = "GetIonoGridGIVEI";
    const char* const GetIonoGridGIVEI::Documentation = "Get the GIVEI for a ionospheric grid point";

    REGISTER_COMMAND_FACTORY(GetIonoGridGIVEI);


    GetIonoGridGIVEI::GetIonoGridGIVEI()
      : CommandBase(CmdName)
    {}

    GetIonoGridGIVEI::GetIonoGridGIVEI(int band, int point, const Sdx::optional<std::string>& serviceProvider)
      : CommandBase(CmdName)
    {

      setBand(band);
      setPoint(point);
      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIPtr GetIonoGridGIVEI::create(int band, int point, const Sdx::optional<std::string>& serviceProvider)
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
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEI::documentation() const { return Documentation; }


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



    Sdx::optional<std::string> GetIonoGridGIVEI::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEI::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
