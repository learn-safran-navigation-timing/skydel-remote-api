#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouPerturbations
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Prn  int    Satellite PRN number 1..30
    /// Crs  double Crs (meter)
    /// Crc  double Crc (meter)
    /// Cis  double Crs (rad)
    /// Cic  double Crc (rad)
    /// Cus  double Cus (rad)
    /// Cuc  double Cuc (rad)
    ///

    class GetBeiDouPerturbationsResult;
    typedef std::shared_ptr<GetBeiDouPerturbationsResult> GetBeiDouPerturbationsResultPtr;
    
    
    class GetBeiDouPerturbationsResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouPerturbationsResult();

      GetBeiDouPerturbationsResult(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
  
      static GetBeiDouPerturbationsResultPtr create(CommandBasePtr relatedCommand, int prn, double crs, double crc, double cis, double cic, double cus, double cuc);
      static GetBeiDouPerturbationsResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** crs ****
      double crs() const;
      void setCrs(double crs);


      // **** crc ****
      double crc() const;
      void setCrc(double crc);


      // **** cis ****
      double cis() const;
      void setCis(double cis);


      // **** cic ****
      double cic() const;
      void setCic(double cic);


      // **** cus ****
      double cus() const;
      void setCus(double cus);


      // **** cuc ****
      double cuc() const;
      void setCuc(double cuc);
    };
  }
}

