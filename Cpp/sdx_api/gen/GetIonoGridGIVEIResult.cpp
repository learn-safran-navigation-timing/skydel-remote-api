
#include "GetIonoGridGIVEIResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEIResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEIResult::CmdName = "GetIonoGridGIVEIResult";
    const char* const GetIonoGridGIVEIResult::Documentation = "Result of GetIonoGridGIVEI.\n"
      "\n"
      "Name            Type            Description\n"
      "--------------- --------------- -------------------------------\n"
      "Band            int             The ionospheric grid band index\n"
      "Point           int             The IGP index\n"
      "GiveI           int             The GIVEI at the IGP\n"
      "ServiceProvider optional string The service provider (optional)";
    const char* const GetIonoGridGIVEIResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetIonoGridGIVEIResult);


    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId)
    {

      setBand(band);
      setPoint(point);
      setGiveI(giveI);
      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult(CommandBasePtr relatedCommand, int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setBand(band);
      setPoint(point);
      setGiveI(giveI);
      setServiceProvider(serviceProvider);
    }


    GetIonoGridGIVEIResultPtr GetIonoGridGIVEIResult::create(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEIResult>(band, point, giveI, serviceProvider);
    }

    GetIonoGridGIVEIResultPtr GetIonoGridGIVEIResult::create(CommandBasePtr relatedCommand, int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
    {
      return std::make_shared<GetIonoGridGIVEIResult>(relatedCommand, band, point, giveI, serviceProvider);
    }

    GetIonoGridGIVEIResultPtr GetIonoGridGIVEIResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIonoGridGIVEIResult>(ptr);
    }

    bool GetIonoGridGIVEIResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Band"])
          && parse_json<int>::is_valid(m_values["Point"])
          && parse_json<int>::is_valid(m_values["GiveI"])
          && parse_json<Sdx::optional<std::string>>::is_valid(m_values["ServiceProvider"])
        ;

    }

    std::string GetIonoGridGIVEIResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetIonoGridGIVEIResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Band", "Point", "GiveI", "ServiceProvider"}; 
      return names; 
    }


    int GetIonoGridGIVEIResult::band() const
    {
      return parse_json<int>::parse(m_values["Band"]);
    }

    void GetIonoGridGIVEIResult::setBand(int band)
    {
      m_values.AddMember("Band", parse_json<int>::format(band, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridGIVEIResult::point() const
    {
      return parse_json<int>::parse(m_values["Point"]);
    }

    void GetIonoGridGIVEIResult::setPoint(int point)
    {
      m_values.AddMember("Point", parse_json<int>::format(point, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIonoGridGIVEIResult::giveI() const
    {
      return parse_json<int>::parse(m_values["GiveI"]);
    }

    void GetIonoGridGIVEIResult::setGiveI(int giveI)
    {
      m_values.AddMember("GiveI", parse_json<int>::format(giveI, m_values.GetAllocator()), m_values.GetAllocator());
    }



    Sdx::optional<std::string> GetIonoGridGIVEIResult::serviceProvider() const
    {
      return parse_json<Sdx::optional<std::string>>::parse(m_values["ServiceProvider"]);
    }

    void GetIonoGridGIVEIResult::setServiceProvider(const Sdx::optional<std::string>& serviceProvider)
    {
      m_values.AddMember("ServiceProvider", parse_json<Sdx::optional<std::string>>::format(serviceProvider, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
