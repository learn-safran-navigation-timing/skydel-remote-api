
#include "gen/GetIonoGridMask.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridMask
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridMask::CmdName = "GetIonoGridMask";
    const char* const GetIonoGridMask::Documentation = "Get the flag for a ionospheric grid point in the SBAS message 18 mask";

    REGISTER_COMMAND_FACTORY(GetIonoGridMask);


    GetIonoGridMask::GetIonoGridMask()
      : CommandBase(CmdName)
    {}

    GetIonoGridMask::GetIonoGridMask(const std::string& serviceProvider, int band, int point)
      : CommandBase(CmdName)
    {

      setServiceProvider(serviceProvider);
      setBand(band);
      setPoint(point);
    }

    GetIonoGridMaskPtr GetIonoGridMask::create(const std::string& serviceProvider, int band, int point)
    {
      return std::make_shared<GetIonoGridMask>(serviceProvider, band, point);
    }

    GetIonoGridMaskPtr GetIonoGridMask::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridMask>(ptr);
    }

    bool GetIonoGridMask::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["ServiceProvider"])
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
        ;

    }

    std::string GetIonoGridMask::documentation() const { return Documentation; }


    int GetIonoGridMask::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string GetIonoGridMask::serviceProvider() const
    {
      return parse_json<std::string>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridMask::setServiceProvider(const std::string& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<std::string>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMask::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridMask::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridMask::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridMask::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
