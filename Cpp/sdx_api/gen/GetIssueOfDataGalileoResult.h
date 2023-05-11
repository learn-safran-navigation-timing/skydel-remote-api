#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetIssueOfDataGalileo.
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------------
    /// Navigation    int           Issue of data, navigation
    /// Almanac       int           Issue of data, almanac
    /// OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True
    ///

    class GetIssueOfDataGalileoResult;
    typedef std::shared_ptr<GetIssueOfDataGalileoResult> GetIssueOfDataGalileoResultPtr;
    
    
    class GetIssueOfDataGalileoResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIssueOfDataGalileoResult();

      GetIssueOfDataGalileoResult(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});

      GetIssueOfDataGalileoResult(CommandBasePtr relatedCommand, int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});

      static GetIssueOfDataGalileoResultPtr create(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});

      static GetIssueOfDataGalileoResultPtr create(CommandBasePtr relatedCommand, int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});
      static GetIssueOfDataGalileoResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** navigation ****
      int navigation() const;
      void setNavigation(int navigation);


      // **** almanac ****
      int almanac() const;
      void setAlmanac(int almanac);


      // **** overrideRinex ****
      Sdx::optional<bool> overrideRinex() const;
      void setOverrideRinex(const Sdx::optional<bool>& overrideRinex);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetIssueOfDataGalileoResult);
  }
}

