#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set tropospheric model
    ///
    /// Name  Type   Description
    /// ----- ------ -----------------------------------------------------------------
    /// Model string Tropospheric model ("None", "Saastamoinen", "Stanag" or "DO-229")
    ///

    class SetTropoModel;
    typedef std::shared_ptr<SetTropoModel> SetTropoModelPtr;
    
    
    class SetTropoModel : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetTropoModel();

      SetTropoModel(const std::string& model);

      static SetTropoModelPtr create(const std::string& model);
      static SetTropoModelPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** model ****
      std::string model() const;
      void setModel(const std::string& model);
    };
    
  }
}

