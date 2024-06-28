#pragma once

#include <memory>
#include "command_base.h"

#include <optional>

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
      static const char* const TargetId;


      SetIssueOfDataGalileo();

      SetIssueOfDataGalileo(int navigation, int almanac, const std::optional<bool>& overrideRinex = {});

      static SetIssueOfDataGalileoPtr create(int navigation, int almanac, const std::optional<bool>& overrideRinex = {});
      static SetIssueOfDataGalileoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** navigation ****
      int navigation() const;
      void setNavigation(int navigation);


      // **** almanac ****
      int almanac() const;
      void setAlmanac(int almanac);


      // **** overrideRinex ****
      std::optional<bool> overrideRinex() const;
      void setOverrideRinex(const std::optional<bool>& overrideRinex);
    };
    
  }
}

