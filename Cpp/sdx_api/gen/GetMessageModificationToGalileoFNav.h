#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the Galileo F/NAV message modification with this ID.
    ///
    /// Name Type   Description
    /// ---- ------ ------------------------------
    /// Id   string Unique identifier of the event
    ///

    class GetMessageModificationToGalileoFNav;
    typedef std::shared_ptr<GetMessageModificationToGalileoFNav> GetMessageModificationToGalileoFNavPtr;
    
    
    class GetMessageModificationToGalileoFNav : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetMessageModificationToGalileoFNav();

      GetMessageModificationToGalileoFNav(const std::string& id);

      static GetMessageModificationToGalileoFNavPtr create(const std::string& id);
      static GetMessageModificationToGalileoFNavPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

