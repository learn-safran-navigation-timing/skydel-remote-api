#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the GPS ionospheric Beta coefficient
    /// Beta 0 is in seconds
    /// Beta 1 is in seconds/semicircle
    /// Beta 2 is in seconds/semicircle^2
    /// Beta 3 is in seconds/semicircle^3
    ///
    /// Name  Type Description
    /// ----- ---- ------------------------
    /// Index int  Coefficient index [0..3]
    ///

    class GetIonoBeta;
    typedef std::shared_ptr<GetIonoBeta> GetIonoBetaPtr;
    
    
    class GetIonoBeta : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIonoBeta();

      GetIonoBeta(int index);

      static GetIonoBetaPtr create(int index);
      static GetIonoBetaPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** index ****
      int index() const;
      void setIndex(int index);
    };
    
  }
}

