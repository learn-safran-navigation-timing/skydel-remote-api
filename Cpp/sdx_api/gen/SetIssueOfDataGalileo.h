#pragma once

#include <memory>
#include "command_base.h"

#include "sdx_optional.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)
    ///
    /// Name          Type          Description
    /// ------------- ------------- ---------------------------------------------------------
    /// Navigation    int           Issue of data, navigation
    /// Almanac       int           Issue of data, almanac
    /// OverrideRinex optional bool If the IODNAV overrides the RINEX IODNAV, default is True
    ///

    class SetIssueOfDataGalileo;
    typedef std::shared_ptr<SetIssueOfDataGalileo> SetIssueOfDataGalileoPtr;
    
    
    class SetIssueOfDataGalileo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIssueOfDataGalileo();

      SetIssueOfDataGalileo(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});

      static SetIssueOfDataGalileoPtr create(int navigation, int almanac, const Sdx::optional<bool>& overrideRinex = {});
      static SetIssueOfDataGalileoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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
    
  }
}

