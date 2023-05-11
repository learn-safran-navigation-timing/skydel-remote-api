
#include "gen/GetIonoGridGIVEIResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIonoGridGIVEIResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIonoGridGIVEIResult::CmdName = "GetIonoGridGIVEIResult";
    const char* const GetIonoGridGIVEIResult::Documentation = "Result of GetIonoGridGIVEI.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIonoGridGIVEIResult);


    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult()
      : CommandResult(CmdName)
    {}

    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult(int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName)
    {

      setBand(band);
      setPoint(point);
      setGiveI(giveI);
      setServiceProvider(serviceProvider);
    }

    GetIonoGridGIVEIResult::GetIonoGridGIVEIResult(CommandBasePtr relatedCommand, int band, int point, int giveI, const Sdx::optional<std::string>& serviceProvider)
      : CommandResult(CmdName, relatedCommand)
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
